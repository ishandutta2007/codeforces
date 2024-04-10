program problem1;

var N, cnt: byte;
    rows, cols: array[ -1000..1000, 0..1 ] of integer;
    points: array[ 1..200, 0..1 ] of integer;
    i: integer;

begin
  readln( N );

  for i := -1000 to 1000 do
  begin
    rows[i][0] := 1001;
    rows[i][1] := -1001;
    cols[i][0] := 1001;
    cols[i][1] := -1001;
  end;

  for i := 1 to N do
  begin
    readln( points[i][0], points[i][1] );
    if rows[ points[i][1] ][0] > points[i][0] then
      rows[ points[i][1] ][0] := points[i][0];

    if rows[ points[i][1] ][1] < points[i][0] then
      rows[ points[i][1] ][1] := points[i][0];

    if cols[ points[i][0] ][0] > points[i][1] then
      cols[ points[i][0] ][0] := points[i][1];

    if cols[ points[i][0] ][1] < points[i][1] then
      cols[ points[i][0] ][1] := points[i][1];
  end;

  cnt := 0;

  for i := 1 to N do
    if ( points[i][0] <> rows[ points[i][1] ][0] ) and
       ( points[i][0] <> rows[ points[i][1] ][1] ) and
       ( points[i][1] <> cols[ points[i][0] ][0] ) and
       ( points[i][1] <> cols[ points[i][0] ][1] ) then
      inc( cnt );

  writeln( cnt );
end.