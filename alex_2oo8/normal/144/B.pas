program problem2;
type tArr_a = array[1..1000, 0..2] of integer;
     tArr_b = array[-1000..1000, -1000..1000] of boolean;

procedure init( var a: tArr_b; var x1, y1, x2, y2: integer );
var t, i: integer;
begin
  if ( x1 > x2 ) then
  begin
    t := x1;
    x1 := x2;
    x2 := t;
  end;
  if ( y1 > y2 ) then
  begin
    t := y1;
    y1 := y2;
    y2 := t;
  end;

  for i := x1 to x2 do
  begin
    a[i][y1] := true;
    a[i][y2] := true;
  end;
  for i := y1 to y2 do
  begin
    a[x1][i] := true;
    a[x2][i] := true;
  end;
end;

procedure calc( var a: tArr_b; r: tArr_a; x1, y1, x2, y2, n: integer );
var x, y, i: integer;
begin
  for i := 1 to n do
  begin

    x := x1;
    y := r[i][1];
    while ( sqrt( sqr( x - r[i][0] ) + sqr( y - r[i][1] ) ) <= r[i][2] ) do
    begin
      if ( y >= y1 ) and ( y <= y2 ) then
        a[x][y] := false;
      if ( r[i][1] - ( y - r[i][1] ) >= y1 ) and ( r[i][1] - ( y - r[i][1] ) <= y2 ) then
        a[x][ r[i][1] - ( y - r[i][1] ) ] := false;
      inc( y );
    end;

    x := x2;
    y := r[i][1];
    while ( sqrt( sqr( x - r[i][0] ) + sqr( y - r[i][1] ) ) <= r[i][2] ) do
    begin
      if ( y >= y1 ) and ( y <= y2 ) then
        a[x][y] := false;
      if ( r[i][1] - ( y - r[i][1] ) >= y1 ) and ( r[i][1] - ( y - r[i][1] ) <= y2 ) then
        a[x][ r[i][1] - ( y - r[i][1] ) ] := false;
      inc( y );
    end;

    x := r[i][0];
    y := y1;
    while ( sqrt( sqr( x - r[i][0] ) + sqr( y - r[i][1] ) ) <= r[i][2] ) do
    begin
      if ( x >= x1 ) and ( x <= x2 ) then
        a[x][y] := false;
      if ( r[i][0] - ( x - r[i][0] ) >= x1 ) and ( r[i][0] - ( x - r[i][0] ) <= x2 ) then
        a[ r[i][0] - ( x - r[i][0] ) ][y] := false;
      inc( x );
    end;

    x := r[i][0];
    y := y2;
    while ( sqrt( sqr( x - r[i][0] ) + sqr( y - r[i][1] ) ) <= r[i][2] ) do
    begin
      if ( x >= x1 ) and ( x <= x2 ) then
        a[x][y] := false;
      if ( r[i][0] - ( x - r[i][0] ) >= x1 ) and ( r[i][0] - ( x - r[i][0] ) <= x2 ) then
        a[ r[i][0] - ( x - r[i][0] ) ][y] := false;
      inc( x );
    end;
  end;
end;

var xa, ya, xb, yb, n, i: integer;
    cnt: word;
    a: tArr_a;
    b: tArr_b;

begin
  cnt := 0;

  readln( xa, ya, xb, yb );
  readln( n );
  for i := 1 to n do
    readln( a[i][0], a[i][1], a[i][2] );

  init( b, xa, ya, xb, yb );
  calc( b, a, xa, ya, xb, yb, n );

  for i := xa to xb do
  begin
    if ( b[i][ya] ) then
      inc( cnt );
    if ( b[i][yb] ) then
      inc( cnt );
  end;
  for i := ( ya + 1 ) to ( yb - 1 ) do
  begin
    if ( b[xa][i] ) then
      inc( cnt );
    if ( b[xb][i] ) then
      inc( cnt );
  end;

  writeln( cnt );
end.