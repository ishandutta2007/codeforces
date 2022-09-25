program problem2;

var d, n, a, i: longWord;
    ans: qWord;

begin
  ans := 0;
  readln( d, n );
  for i := 1 to (n-1) do
  begin
    read( a );
    ans := ans + d - a;
  end;

  writeln( ans );
end.