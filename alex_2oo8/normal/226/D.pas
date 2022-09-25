program problem4;

var n, m, i, j, cnt, t, k: longInt;
    a: array[ 1..100, 1..100 ] of longInt;
    row, col, rowAns, colAns: array[1..100] of longInt;
    b: boolean;

begin
  fillchar( row, sizeOf(row), 0 );
  fillchar( col, sizeOf(col), 0 );
  fillchar( rowAns, sizeOf(rowAns), 0 );
  fillchar( colAns, sizeOf(colAns), 0 );

  readln( n, m );
  for i := 1 to n do
  begin
    for j := 1 to m do
    begin
      read( a[i][j] );
      inc( row[i], a[i][j] );
      inc( col[j], a[i][j] );
    end;
    readln();
  end;

  while ( true ) do
  begin
    for i := 1 to n do
      if ( row[i] < 0 ) then
      begin
        rowAns[i] := ( rowAns[i] + 1 ) mod 2;
        row[i] := -1 * row[i];
        for j := 1 to m do
        begin
          col[j] := col[j] - ( 2 * a[i][j] );
          a[i][j] := -1 * a[i][j];
        end;

        b := false;
      end;

    for i := 1 to m do
      if ( col[i] < 0 ) then
      begin
        colAns[i] := ( colAns[i] + 1 ) mod 2;
        col[i] := -1 * col[i];
        for j := 1 to n do
        begin
          row[j] := row[j] - ( 2 * a[j][i] );
          a[j][i] := -1 * a[j][i];
        end;

        b := false;
      end;

    b := true;
    for i := 1 to n do
      if ( row[i] < 0 ) then
        b := false;
    for i := 1 to m do
      if ( col[i] < 0 ) then
        b := false;

    if ( b ) then
      break;
  end;

  cnt := 0;
  for i := 1 to n do
    if ( rowAns[i] = 1 ) then
      inc( cnt );
  write( cnt );
  for i := 1 to n do
    if ( rowAns[i] = 1 ) then
      write( ' ', i );
  writeln();

  cnt := 0;
  for i := 1 to m do
    if ( colAns[i] = 1 ) then
      inc( cnt );
  write( cnt );
  for i := 1 to m do
    if ( colAns[i] = 1 ) then
      write( ' ', i );
  writeln();
end.