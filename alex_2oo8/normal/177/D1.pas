program problem4;

var n, m, c, sum, i: longWord;
    a, b: array[1..1000] of longWord;

begin
  readln( n, m, c );

  for i := 1 to n do
    read( a[i] );
  readln;
  for i := 1 to m do
    read( b[i] );
  readln;

  sum := 0;
  for i := 1 to n do
  begin
    if ( i <= m ) then
      sum := ( sum + b[i] ) mod c;

    a[i] := ( a[i] + sum ) mod c;
  end;

  sum := 0;
  for i := 1 to ( m - 1 ) do
  begin
    sum := ( sum + b[i] ) mod c;
    a[ n - m + 1 + i ] := ( a[ n - m + 1 + i ] + c - sum ) mod c;
  end;

  for i := 1 to (n-1) do
    write( a[i], ' ' );
  writeln( a[n] );
end.