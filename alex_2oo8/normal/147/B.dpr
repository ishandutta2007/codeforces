program problem2;
uses math;

type tArr = array[ 1..300, 1..300 ] of longInt;

const inf = trunc( 1.0e+9 );

var n: longWord;
    d: array[0..22] of tArr;

function mult( x, a, b: longWord ): boolean;
var i, j, k: longWord;
begin
  for i := 1 to n do
    for j := 1 to n do
      for k := 1 to n do
        d[x][i][j] := max( d[x][i][j], ( d[a][i][k] + d[b][k][j] ) );

  for i := 1 to n do
    if ( d[x][i][i] > 0 ) then
    begin
      mult := true;
      exit;
    end;
  mult := false;
end;

var m, i, j, k, ans: longInt;

begin
  for i := 0 to 22 do
    for j := 1 to 300 do
      for k := 1 to 300 do
        d[i][j][k] := -inf;

  readln( n, m );

  for i := 1 to n do
  begin
    for j := 1 to n do
      d[0][i][j] := -inf;
    d[0][i][i] := 0;
  end;

  for i := 1 to m do
  begin
    read( j, k );
    read( d[0][j][k] );
    readln( d[0][k][j] );
  end;

  i := 1;
  while ( i <= 10 ) and ( not mult( i, (i-1), (i-1) ) ) do
    inc( i );

  if ( i > 10 ) then
  begin
    writeln( '0' );
    halt;
  end;

  j := i - 2;
  k := i - 1;
  ans := 1 shl (i-1) + 1;
  i := i + 1;
  while ( j >= 0 ) do
  begin
    if ( not mult( i, k, j ) ) then
    begin
      k := i;
      ans := ans + ( 1 shl j );
    end;

    inc( i );
    dec( j );
  end;

  writeln( ans );
end.