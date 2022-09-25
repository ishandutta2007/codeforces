program problem1;

var n, b, i, sum, max: longWord;
    avg: real;
    a: array[1..100] of longWord;

begin
  sum := 0;
  max := 0;

  readln( n, b );
  for i := 1 to n do
  begin
    read( a[i] );
    sum := sum + a[i];
    if ( a[i] ) > max then
      max := a[i];
  end;

  avg := ( sum + b ) / n;

  if ( max > avg ) then
    writeln( '-1' )
  else
    for i := 1 to n do
      writeln( ( avg - a[i] ):0:6 );
end.