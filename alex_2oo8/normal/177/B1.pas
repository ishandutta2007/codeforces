program problem2;

var n, k: longWord;
    sum: qWord;

begin
  readln( n );
  sum := n;
  k := 2;

  while ( n > 1 ) do
  begin
    while ( ( n mod k ) = 0 ) do
    begin
      n := n div k;
      sum := sum + n;
    end;

    inc( k );
  end;

  writeln( sum );
end.