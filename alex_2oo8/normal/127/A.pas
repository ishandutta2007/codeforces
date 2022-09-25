program problem1;

var n, k, i, x, y, lx, ly: longInt;
    ans: real;

begin
  ans := 0;

  readln( n, k );
  readln( lx, ly );
  for i := 2 to n do
  begin
    readln( x, y );
    ans := ans + ( sqrt( sqr( x - lx ) + sqr( y - ly ) ) * k / 50 );
    lx := x;
    ly := y;
  end;

  writeln( ans:0:10 );
end.