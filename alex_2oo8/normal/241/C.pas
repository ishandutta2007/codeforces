program problem3;
uses math;

const eps = 1.0e-9;

var t: array[ 0..1, 0..100005, 0..1 ] of longWord;
    hl, hr: longWord;

function get( a: longWord; x: extended; var r: longWord ): longWord;
begin
  if ( abs( x - trunc(x) ) < eps ) then
  begin
    r := t[a][ trunc(x+eps) ][1];
    exit( t[a][ trunc(x+eps) ][0] );
  end
  else if ( t[a][ trunc(x) ][1] = t[a][ trunc(x) + 1 ][1] ) then
  begin
    r := t[a][ trunc(x) ][1];
    exit( t[a][ trunc(x) ][0] );
  end
  else
    exit( 0 );
end;

function calc( p: extended; a: longWord; var res: longWord ): boolean;
var x: extended;
    k, r: longWord;
    last: array[0..1] of longWord;
begin
  fillchar( last, sizeOf(last), 0 );

  res := 0;
  if ( a = 1 ) then
    x := ( p * hl ) / 100
  else
    x := ( p * (100-hl) ) / 100;

  while ( (x-eps) < 100000 ) do
  begin
    k := get( a, x, r );
    if ( k = 0 ) or ( r = last[a] ) then
    begin
      res := 0;
      exit( false );
    end;

    last[a] := r;
    inc( res, k );
    x := x + p;
    a := 1 - a;
  end;

  exit( true );
end;

var n, i, j, k, v, a, b, ans: longWord;
    c: char;
    p, x: extended;

begin
  fillchar( t, sizeOf(t), 0 );

  readln( hl, hr, n );
  for i := 1 to n do
  begin
    readln( v, c, c, a, b );
    if ( c = 'T' ) then
      for j := a to b do
      begin
        t[0][j][0] := v;
        t[0][j][1] := i;
      end;

    if ( c = 'F' ) then
      for j := a to b do
      begin
        t[1][j][0] := v;
        t[1][j][1] := i;
      end;
  end;

  ans := 0;
  for i := 0 to (n-1) do
    for a := 0 to 1 do
    begin
      if ( a = 0 ) and ( odd(i) ) then
        p := 100000 / ( i + 1 - (hl/100) + (hr/100) )
      else if ( a = 0 ) and ( not odd(i) ) then
        p := 100000 / ( i + 1 - (hl/100) + 1 - (hr/100) )
      else if ( a = 1 ) and ( odd(i) ) then
        p := 100000 / ( i + (hl/100) + 1 - (hr/100) )
      else
        p := 100000 / ( i + (hl/100) + (hr/100) );

      if ( calc( p, a, v ) ) then
        ans := max( ans, v );
    end;

  writeln( ans );
end.