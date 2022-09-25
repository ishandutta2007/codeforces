program problem1;

var n, i, j, a: longWord;
    sum: qWord;

begin
  sum := 0;

  readln( n );
  for i := 1 to n do
  begin
    for j := 1 to n do
    begin
      read( a );
      if ( i = j ) or ( (n-i) = (j-1) ) or ( i = ( (n+1) div 2 ) ) or ( j = ( (n+1) div 2 ) ) then
        sum := sum + a;
    end;
    readln;
  end;

  writeln( sum );
end.