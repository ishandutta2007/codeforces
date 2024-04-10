program problem2;

var n, sum, i: word;
    d: array[1..7] of word;

begin
  sum := 0;

  readln( n );
  for i := 1 to 7 do
  begin
    read( d[i] );
    sum := sum + d[i];
  end;

  n := ( n mod sum ) + sum;

  while true do
    for i := 1 to 7 do
    begin
      if ( n <= d[i] ) then
      begin
        writeln( i );
        halt;
      end
      else
        n := n - d[i];
  end;
end.