program problem5;

type tArr = array[ 1..100000, 0..2 ] of longWord;

procedure add( var h: tArr; v0, v1, v2: longWord; var n: longWord );
var i: longWord;
begin
  inc( n );
  i := n;
  while ( i > 1 ) and ( ( v0 < h[i div 2][0] ) or ( ( v0 = h[i div 2][0] ) and ( v1 < h[i div 2][1] ) ) ) do
  begin
    h[i] := h[i div 2];
    i := i div 2;
  end;
  h[i][0] := v0;
  h[i][1] := v1;
  h[i][2] := v2;
end;

procedure del( var h: tArr; var n: longWord );
var i, iMin: longWord;
begin
  dec( n );
  i := 1;
  while ( (2*i) <= n ) do
  begin
    if ( (2*i) = n ) or ( h[2*i][0] < h[2*i+1][0] ) or ( ( h[2*i][0] = h[2*i+1][0] ) and ( h[2*i][1] < h[2*i+1][1] ) ) then
      iMin := 2 * i
    else
      iMin := 2 * i + 1;

    if ( h[n+1][0] < h[iMin][0] ) or ( ( h[n+1][0] = h[iMin][0] ) and ( h[n+1][1] < h[iMin][1] ) ) then
      break;

    h[i] := h[iMin];
    i := iMin;
  end;
  h[i] := h[n+1];
end;

var n, m, i, j, nH, nS, r, c, ans: longWord;
    ansArr: array[1..100000] of longWord;
    h, s: tArr;

begin
  readln( n, m );

  nS := 0;
  nH := 0;

  for i := 1 to m do
  begin
    readln( r, c );
    r := n - r + 1;
    add( s, r, c, i, nS );
  end;

  for i := 1 to n do
  begin
    while ( nS > 0 ) and ( s[1][0] = i ) do
    begin
      add( h, s[1][1], s[1][0], s[1][2], nH );
      del( s, nS );
    end;

    while ( nH > 0 ) and ( h[1][0] < i ) do
      del( h, nH );

    if ( nH > 0 ) then
    begin
      inc( ans );
      ansArr[ans] := h[1][2];
      del( h, nH );
    end;
  end;

  writeln( ans );
  for i := 1 to ans do
    write( ansArr[i], ' ' );
end.