program problem1;

function nod( a, b: longWord ): longWord;
var t: longWord;
begin
  if ( a < b ) then
  begin
    t := a;
    a := b;
    b := t;
  end;

  while b > 0 do
  begin
    a := a mod b;
    if ( a < b ) then
    begin
      t := a;
      a := b;
      b := t;
    end;
  end;

  nod := a;
end;

function checkWin( ch1, ch2: char ): byte;
begin
  if ( ch1 = 'R' ) then
  begin
    if ( ch2 = 'R' ) then
      checkWin := 2
    else if ( ch2 = 'S' ) then
      checkWin := 0
    else if ( ch2 = 'P' ) then
      checkWin := 1;
  end
  else if ( ch1 = 'S' ) then
  begin
    if ( ch2 = 'R' ) then
      checkWin := 1
    else if ( ch2 = 'S' ) then
      checkWin := 2
    else if ( ch2 = 'P' ) then
      checkWin := 0;
  end
  else if ( ch1 = 'P' ) then
  begin
    if ( ch2 = 'R' ) then
      checkWin := 0
    else if ( ch2 = 'S' ) then
      checkWin := 1
    else if ( ch2 = 'P' ) then
      checkWin := 2;
  end;
end;

var n, m, k, i, ans1, ans2: longWord;
l: qWord;
    a, b, c: ansistring;
    rez: array[0..1000000, 0..2] of longWord;

begin
  ans1 := 0;
  ans2 := 0;

  readln( n );
  readln( a );
  readln( b );
  l := ( length(a) * length(b) ) div nod( length(a), length(b) );

  c := '';
  for i := 1 to ( l div length(a) ) do
    c := c + a;
  a := c;

  c := '';
  for i := 1 to ( l div length(b) ) do
    c := c + b;
  b := c;


  rez[0][0] := 0;
  rez[0][1] := 0;
  for i := 1 to l do
  begin
    rez[i][0] := rez[i-1][0];
    rez[i][1] := rez[i-1][1];
    rez[i][2] := 0;

    inc( rez[i][ checkWin( a[i], b[i] ) ] );
  end;

  if ( n >= l ) then
  begin
    ans1 := ans1 + ( ( n div l ) * rez[l][0] );
    ans2 := ans2 + ( ( n div l ) * rez[l][1] );
    n := n mod l;
  end;
  ans1 := ans1 + rez[n][0];
  ans2 := ans2 + rez[n][1];

  writeln( ans2, ' ', ans1 );
end.