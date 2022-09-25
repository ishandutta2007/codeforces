program problem4;
uses math;

const eps = 1.0e-8;

var a, v, ld, d, w: longInt;
    t, t1, t2, s1, s2, l, r, c, v1, _D: real;

begin
  readln( a, v, ld, d, w );
  ld := ld - d;

  t1 := v / a;
  s1 := t1 * v / 2;
  t2 := max( (v-w), 0 ) / a;
  s2 := t2 * ( v + w ) / 2;

  if ( ( s1 + s2 ) <= d ) then
  begin
    t := t1 + t2 + ( (d-s1-s2) / v );
    v1 := w;
  end
  else
  begin
    l := 0;
    r := v;
    while ( true ) do
    begin
      c := (l+r) / 2;
      t1 := c / a;
      s1 := t1 * c / 2;
      t2 := max( (c-w), 0 ) / a;
      s2 := t2 * (c+w) / 2;

      if ( abs(d-s1-s2) < eps ) then
      begin
        t := t1 + t2 + ( (d-s1-s2) / c );
        v1 := min( c, w );
        break;
      end;

      if ( (s1+s2) > d ) then
        r := c
      else
        l := c;
    end;
  end;

  t1 := max( (v-v1), 0 ) / a;
  s1 := t1 * (v+v1) / 2;

  if ( s1 < ld ) then
    t := t + t1 + ( (ld-s1) / v )
  else
  begin
    _D := ( sqr(2*v1) - 4*a*(-2*ld) );
    t1 := ( -2*v1 + sqrt(_D) ) / (2*a);
    t2 := ( -2*v1 - sqrt(_D) ) / (2*a);

    if ( t1 > 0 ) then
      t := t + t1
    else
      t := t + t2;
  end;

  writeln( t:0:12 );
end.