program prblem1;

var r1, r2, c1, c2, d1, d2, x1y1, x1y2, x2y1, x2y2: byte;
    bool: boolean;

begin
  bool := false;
  readln( r1, r2 );
  readln( c1, c2 );
  readln( d1, d2 );

  for x1y1 := 1 to 9 do
  begin
    x2y1 := c1 - x1y1;
    x1y2 := r1 - x1y1;
    x2y2 := d1 - x1y1;

    if ( ( x2y1 + x2y2 ) = r2 ) and ( ( x1y2 + x2y2 ) = c2 ) and ( ( x2y1 + x1y2 ) = d2 ) and
       ( x1y1 <> x1y2 ) and ( x1y1 <> x2y1 ) and ( x1y1 <> x2y2 ) and ( x1y2 <> x2y1 ) and ( x1y2 <> x2y2 ) and ( x2y1 <> x2y2 ) and
       ( x1y1 in [1..9] ) and ( x1y2 in [1..9] ) and ( x2y1 in [1..9] ) and ( x2y2 in [1..9] ) then
    begin
      bool := true;
      writeln( x1y1, ' ', x1y2 );
      writeln( x2y1, ' ', x2y2 );
      break;
    end;
  end;

  if not bool then
    writeln( '-1' );
end.