program problem2;

function min( a, b: longWord ): longWord;
begin
  if ( a < b ) then
    min := a
  else
    min := b;
end;

var n, m, x, y, i, a, b, c: longWord;
    cnt: qWord;
    d: array[ 0..10000, 0..1 ] of longInt;

begin
  cnt := 0;

  read  ( n );
  readln( m );
  read  ( x );
  readln( y );
  readln( d[0][0] );
  for i := 1 to d[0][0] do
  begin
    read  ( d[i][0] );
    readln( d[i][1] );
  end;

  for i := 1 to d[0][0] do
  begin
    if ( d[i][0] < 0 ) then
      a := (x-1) div abs( d[i][0] )
    else if ( d[i][0] > 0 ) then
      a := (n-x) div d[i][0]
    else
      a := 4294967295;

    if ( d[i][1] < 0 ) then
      b := (y-1) div abs( d[i][1] )
    else if ( d[i][1] > 0 ) then
      b := (m-y) div d[i][1]
    else
      b := 4294967295;

    c := min( a, b );

    cnt := cnt + c;
    x := x + ( d[i][0] * c );
    y := y + ( d[i][1] * c );
  end;

  writeln( cnt );
end.