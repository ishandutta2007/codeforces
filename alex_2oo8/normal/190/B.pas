program problem2;
uses math;

var x1, y1, x2, y2, r1, r2: longInt;
    ans, d: real;

begin
  readln( x1, y1, r1, x2, y2, r2 );

  d := sqrt( sqr(x1-x2) + sqr(y1-y2) );

  if ( max( r1, r2 ) > (min( r1, r2 ) + d) ) then
    ans := ( max( r1, r2 ) - d - min( r1, r2 ) ) / 2
  else
    ans := max( (d-r1-r2), 0 ) / 2;

  writeln( ans:0:12 );
end.