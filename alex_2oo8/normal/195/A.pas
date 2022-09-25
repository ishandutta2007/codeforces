program problem1;

var a, b, c, ans: longWord;

begin
  readln( a, b, c );

  ans := ( ( c * a + b - 1 ) div b ) - c;

  writeln( ans );
end.