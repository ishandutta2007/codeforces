program problem1;
uses math;

var n, a, b: longWord;

begin
  readln( n, a, b );
  writeln( min( (n-a), (b+1) ) );
end.