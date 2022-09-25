program problem2;

var n, p, sum, i: longWord;

begin
  sum := 0;

  readln( n );
  for i := 1 to n do
  begin
    read( p );
    inc( sum, p );
  end;

  writeln( (sum/n):0:12 );
end.