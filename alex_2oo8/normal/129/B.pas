program problem2;

var n, m, a, b, ans, i, j: longInt;
    arr: array[ 1..100, 0..100 ] of shortInt;
    group: array[ 0..100 ] of byte;

begin
  ans := 0;

  readln( n, m );
  for i := 1 to n do
    arr[i][0] := 0;

  for i := 1 to m do
  begin
    readln( a, b );
    inc( arr[a][0] );
    inc( arr[b][0] );
    arr[a][ arr[a][0] ] := b;
    arr[b][ arr[b][0] ] := a;
  end;

  repeat
    group[0] := 0;
    for i := 1 to n do
      if ( arr[i][0] = 1 ) then
      begin
        inc( group[0] );
        group[ group[0] ] := i;
      end;

    for i := 1 to group[0] do
    begin
      arr[ group[i] ][0] := 0;
      dec( arr[ arr[ group[i] ][1] ][0] );
      for j := 1 to arr[ arr[ group[i] ][1] ][0] do
        if ( arr[ arr[ group[i] ][1] ][j] = group[i] ) then
          arr[ arr[ group[i] ][1] ][j] := arr[ arr[ group[i] ][1] ][ arr[ arr[ group[i] ][1] ][0] + 1 ];
    end;

    if ( group[0] > 0 ) then
      inc( ans );
  until ( group[0] = 0 );

  writeln( ans );
end.