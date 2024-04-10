program problem5;
uses math;

type tRec = record
              d: longWord;
              b: array[1..8] of qWord;
            end;

var dp: array[ 0..501, 0..501, 0..1, 1..10 ] of tRec;
    a: array[ 1..500, 1..500 ] of char;
    n: longWord;

procedure firstCell( var x, y: longWord; d: longWord );
begin
  if ( d <= n ) then
  begin
    x := d;
    y := 1;
  end
  else
  begin
    x := n;
    y := d - n + 1;
  end;

end;

procedure proc( l, r, k: longWord );
var i, p, d, x, y: longWord;
begin
  d := (l+r) div 2;

  firstCell( x, y, d );

  p := 1;
  while ( x > 0 ) and ( y <= n ) do
  begin
    dp[x][y][0][k].d := d;
    dp[x][y][1][k].d := d;

    if ( a[x][y] = '.' ) then
    begin
      dp[x][y][0][k].b[ (p+63) div 64 ] := qWord(1) shl ( (p-1) mod 64 );
      dp[x][y][1][k].b[ (p+63) div 64 ] := qWord(1) shl ( (p-1) mod 64 );
    end;

    dec( x );
    inc( y );
    inc( p );
  end;

  for p := (d-1) downTo l do
  begin
    firstCell( x, y, p );

    while ( x > 0 ) and ( y <= n ) do
    begin
      dp[x][y][0][k].d := d;

      if ( a[x][y] = '.' ) then
        for i := 1 to 8 do
          dp[x][y][0][k].b[i] := dp[x+1][y][0][k].b[i] or dp[x][y+1][0][k].b[i];

      dec( x );
      inc( y );
    end;
  end;

  for p := (d+1) to r do
  begin
    firstCell( x, y, p );

    while ( x > 0 ) and ( y <= n ) do
    begin
      dp[x][y][1][k].d := d;

      if ( a[x][y] = '.' ) then
        for i := 1 to 8 do
          dp[x][y][1][k].b[i] := dp[x-1][y][1][k].b[i] or dp[x][y-1][1][k].b[i];

      dec( x );
      inc( y );
    end;
  end;

  if ( d <> l ) then
    proc( l, (d-1), (k+1) );
  if ( r <> d ) then
    proc( (d+1), r, (k+1) );
end;

function check( x1, y1, x2, y2: longWord ): boolean;
var i, j: longWord;
begin
  i := 1;
  while ( dp[x1][y1][0][i].d <> dp[x2][y2][1][i].d ) do
    inc( i );

  for j := 1 to 8 do
    if ( ( dp[x1][y1][0][i].b[j] and dp[x2][y2][1][i].b[j] ) > 0 ) then
      exit( true );

  check := false;
end;

var m, i, j, x1, y1, x2, y2: longWord;

begin
  fillchar( a, sizeOf(a), '#' );
  fillchar( dp, sizeOf(dp), 0 );

  readln( n, m );
  for i := 1 to n do
  begin
    for j := 1 to m do
      read( a[i][j] );
    readln();
  end;

  n := max( n, m );

  proc( 1, (2*n-1), 1 );

  readln( m );
  for i := 1 to m do
  begin
    readln( x1, y1, x2, y2 );
    if ( x1 > x2 ) or ( y1 > y2 ) or ( not check( x1, y1, x2, y2 ) ) then
      writeln( 'No' )
    else
      writeln( 'Yes' );
  end;
end.