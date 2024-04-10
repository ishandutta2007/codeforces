program problem2;

const eps = 1.0e-8;

var vp, vd, t, f, c, ans: longWord;
    s, k: real;

begin
  readln( vp, vd, t, f, c );

  if ( vd <= vp ) then
  begin
    writeln( '0' );
    halt;
  end;

  ans := 0;
  s := t * vp;
  while ( (c-s) > eps ) do
  begin
    k := s / ( vd - vp );
    s := s + ( k * vp );
    if ( (c-s) > eps ) then
    begin
      inc( ans );
      s := s + ( (k+f) * vp );
    end;
  end;

  writeln( ans );
end.