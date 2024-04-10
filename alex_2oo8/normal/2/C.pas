program problem3;
uses math;

const eps = 1.0e-6;

type point = record
               x, y, r: extended;
             end;
     tPointRec = record
                    t: longWord;
                    P0, P1: point;
                  end;

function distance( A, B: point ): extended;
begin
  distance := sqrt( sqr( A.x - B.x ) + sqr( A.y - B.y ) );
end;

procedure proc( A, B: point; AB: extended; var P: tPointRec );
var P2, P3: point;
begin
  if ( A.r = B.r ) then
  begin
    P.t := 0;
    P2.x := ( A.x + B.x ) / 2;
    P2.y := ( A.y + B.y ) / 2;
    P.P0.x := P2.x + ( A.y - B.y );
    P.P0.y := P2.y - ( A.x - B.x );
    P.P1.x := P2.x - ( A.y - B.y );
    P.P1.y := P2.y + ( A.x - B.x );
  end
  else
  begin
    P2.x := A.x + ( A.r * (B.x-A.x) / ( A.r + B.r ) );
    P2.y := A.y + ( A.r * (B.y-A.y) / ( A.r + B.r ) );
    P3.x := A.x + ( ( AB * A.r / (A.r-B.r) ) * (B.x-A.x) / AB );
    P3.y := A.y + ( ( AB * A.r / (A.r-B.r) ) * (B.y-A.y) / AB );

    P.t := 1;
    P.P0.x := ( P2.x + P3.x ) / 2;
    P.P0.y := ( p2.y + P3.y ) / 2;
    P.P0.r := sqrt( sqr( P2.x - P3.x ) + sqr( P2.y - P3.y ) ) / 2;
  end;
end;


procedure calc( P0, P1: point; var P3, P4: point );
var a, h, d: extended;
    P2: point;
begin
  if ( P0.r < P1.r ) then
  begin
    P2 := P0;
    P0 := P1;
    P1 := P2;
  end;

  d := distance( P0, P1 );

  if ( d < abs( P0.r - P1.r ) ) or ( d > ( P0.r + P1.r ) ) then
    halt;

  a := ( sqr(P0.r) - sqr(P1.r) + sqr(d) ) / (2*d);
  P2.x := P0.x + ( a * (P1.x-P0.x) / d );
  P2.y := P0.y + ( a * (P1.y-P0.y) / d );
  if ( abs( a - (P0.r) ) < eps ) then
  begin
    P3 := P2;
    P4 := P2;
  end
  else
  begin
    h := sqrt( sqr(P0.r) - sqr(a) );
    P3.x := P2.x + ( h * ( P1.y - P0.y ) / d );
    P3.y := P2.y - ( h * ( P1.x - P0.x ) / d );
    P4.x := P2.x - ( h * ( P1.y - P0.y ) / d );
    P4.y := P2.y + ( h * ( P1.x - P0.x ) / d );
  end;
end;

procedure calc2( a, b: tPointRec; var P0, P1: point );
var A1, B1, C1, A2, B2, C2: extended;
begin
  A1 := a.P0.y - a.P1.y;
  B1 := a.P1.x - a.p0.x;
  C1 := ( a.P0.x * a.P1.y ) - ( a.P1.x * a.P0.y );

  A2 := b.P0.y - b.P1.y;
  B2 := b.P1.x - b.p0.x;
  C2 := ( b.P0.x * b.P1.y ) - ( b.P1.x * b.P0.y );

  if ( ( (A1*B2) - (A2*B1) ) = 0 ) then
    halt;

  P0.x := 0 + -1 * ( (C1*B2) - (C2*B1) ) / ( (A1*B2) - (A2*B1) );
  P0.y := 0 + -1 * ( (A1*C2) - (A2*C1) ) / ( (A1*B2) - (A2*B1) );
  P1 := P0;
end;

procedure calc3( a, b: tPointRec; var P0, P1: point );
var P2: point;
    P3: tPointRec;
    t: TpointRec;
    c, d: extended;
begin
  if ( b.t = 0 ) then
  begin
    t := a;
    a := b;
    b := t;
  end;

  P3.P0.x := b.P0.x + ( a.P0.x - a.P1.x );
  P3.P0.y := b.P0.y - ( a.P0.y - a.P1.y );
  P3.P1 := b.P0;

  calc2( a, P3, P2, P2 );

  if ( distance( P2, b.P0 ) > b.P0.r ) then
    halt;

  c := sqrt( sqr( b.P0.r ) - sqr( distance( P2, b.P0 ) ) );
  d := distance( a.P0, a.P1 );

  P0.x := P2.x + ( c * ( a.P0.x - a.P1.x ) / d );
  P0.y := P2.y + ( c * ( a.P0.y - a.P1.y ) / d );

  P1.x := P2.x - ( c * ( a.P0.x - a.P1.x ) / d );
  P1.y := P2.y - ( c * ( a.P0.y - a.P1.y ) / d );
end;

function check( A, B, C, P: point ): boolean;
var k: extended;
begin
  k := distance( A, P ) / A.r;
  check := ( abs( k - ( distance( B, P ) / B.r ) ) < eps ) and ( abs( k - ( distance( C, P ) / C.r ) ) < eps );
end;

var A, B, C, P2, P3: point;
    points: array[1..2] of tPointRec;

begin
  readln( A.x, A.y, A.r, B.x, B.y, B.r, C.x, C.y, C.r );

  proc( A, B, distance( A, B ), points[1] );
  proc( A, C, distance( A, C ), points[2] );

  if ( points[1].t = 1 ) and ( points[2].t = 1 ) then
    calc( points[1].P0, points[2].P0, P2, P3 )
  else if ( points[1].t = 0 ) and ( points[2].t = 0 ) then
    calc2( points[1], points[2], P2, P3 )
  else
    calc3( points[1], points[2], P2, P3 );

  if ( not check( A, B, C, P2 ) ) then
  begin
    if ( check( A, B, C, P3 ) ) then
      writeln( P3.x:0:12, ' ', P3.y:0:12 );
  end
  else if ( not check( A, B, C, P3 ) ) then
    writeln( P2.x:0:12, ' ', P2.y:0:12 )
  else if ( distance( P2, A ) < distance( P3, A ) ) then
    writeln( P2.x:0:12, ' ', P2.y:0:12 )
  else
    writeln( P3.x:0:12, ' ', P3.y:0:12 );
end.