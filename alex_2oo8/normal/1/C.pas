program problem3;
const eps = 1.0e-3;

type point = record
              x, y: real;
            end;

function arcSin( sin: real ): real;
begin
  if ( abs(sin-1.0) < sqr(eps) ) then
    arcSin := pi / 2
  else
    arcSin := arcTan( sin / Sqrt( 1 - sqr(sin) ) );
end;

var A, B, C: point;
    r, k, AB, AC, BC, p, AOB, AOC, BOC, S: real;
    n: longWord;

begin
  readln( A.x, A.y, B.x, B.y, C.x, C.y );

  AB := sqrt( sqr( A.x - B.x ) + sqr( A.y - B.y ) );
  AC := sqrt( sqr( A.x - C.x ) + sqr( A.y - C.y ) );
  BC := sqrt( sqr( C.x - B.x ) + sqr( C.y - B.y ) );

  p := ( AB + AC + BC ) / 2;
  r := ( AB * AC * BC ) / ( 4 * sqrt( p*(p-AB)*(p-AC)*(p-BC) ) );

  AOC := 2 * arcSin( AC / (2*r) );
  AOB := 2 * arcSin( AB / (2*r) );
  BOC := 2 * arcSin( BC / (2*r) );

  for n := 3 to 100 do
  begin
    k := 2 * pi / n;

    if ( ( frac( AOC / k ) < eps ) or ( (1-frac( AOC / k )) < eps ) ) and
       ( ( frac( AOB / k ) < eps ) or ( (1-frac( AOB / k )) < eps ) ) and
       ( ( frac( BOC / k ) < eps ) or ( (1-frac( BOC / k )) < eps ) ) then
    begin
      S := r * cos(k/2) * n * r * sin(k/2);
      writeln( S:0:12 );
      halt;
    end;
  end;
end.