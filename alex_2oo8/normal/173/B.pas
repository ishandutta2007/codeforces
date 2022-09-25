program problem2;

var n, m, ans, i, j: longWord;
    c: array[ 'x'..'y', 1..1000, 0..1000 ] of word;
    arr: array[ 'x'..'y', 0..1000 ] of word;
    xy: array[ 'x'..'y', 1..1000 ] of boolean;
    chr: char;

begin
  ans := 0;

  readln( n, m );
  for i := 1 to n do
  begin
    c['y'][i][0] := 0;
    xy['y'][i] := false;
  end;
  for i := 1 to m do
  begin
    c['x'][i][0] := 0;
    xy['x'][i] := false;
  end;

  for i := n downTo 1 do
  begin
    for j := 1 to m do
    begin
      read( chr );
      if ( chr = '#' ) then
      begin
        inc( c['y'][i][0] );
        c['y'][i][ c['y'][i][0] ] := j;
        inc( c['x'][j][0] );
        c['x'][j][ c['x'][j][0] ] := i;
      end;
    end;
    readln;
  end;

  if ( c['y'][1][0] = 0 ) or ( c['y'][n][0] = 0 ) then
  begin
    writeln( '-1' );
    halt;
  end;

  arr['y'][0] := 1;
  arr['y'][1] := 1;

  while ( ans <= ( 2 * ( n - 1 ) ) ) do
  begin
    if ( ans mod 2 ) = 0 then
    begin
      arr['x'][0] := 0;
      for i := 1 to arr['y'][0] do
        for j := 1 to c['y'][ arr['y'][i] ][0] do
          if ( not xy['x'][ c['y'][ arr['y'][i] ][j] ] ) then
          begin
            inc( arr['x'][0] );
            arr['x'][ arr['x'][0] ] := c['y'][ arr['y'][i] ][j];
            xy['x'][ c['y'][ arr['y'][i] ][j] ] := true;
          end;
    end
    else
    begin
      arr['y'][0] := 0;
      for i := 1 to arr['x'][0] do
        for j := 1 to c['x'][ arr['x'][i] ][0] do
          if ( not xy['y'][ c['x'][ arr['x'][i] ][j] ] ) then
          begin
            inc( arr['y'][0] );
            arr['y'][ arr['y'][0] ] := c['x'][ arr['x'][i] ][j];
            xy['y'][ c['x'][ arr['x'][i] ][j] ] := true;
            if ( arr['y'][ arr['y'][0] ] = n ) then
            begin
              writeln( (ans+1) );
              halt;
            end;
          end;
    end;

    inc( ans );
  end;

  writeln( '-1' );
end.