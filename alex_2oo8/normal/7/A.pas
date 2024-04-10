program problem1;

var i, j, cnt, ans: longWord;
    arr: array[ 0..8, 0..8 ] of char;
    bool: boolean;

begin
  ans := 0;

  for i := 1 to 8 do
  begin
    cnt := 0;
    arr[i][0] := '0';
    for j := 1 to 8 do
    begin
      read( arr[i][j] );
      if ( arr[i][j] = 'B' ) then
        inc( cnt );
    end;
    readln;

    if ( cnt = 8 ) then
    begin
      inc( ans );
      arr[i][0] := '1';
    end;
  end;

  for j := 1 to 8 do
  begin
    cnt := 0;
    bool := false;
    for i := 1 to 8 do
      if ( arr[i][j] = 'B' ) then
      begin
        inc( cnt );
        if ( arr[i][0] = '0' ) then
          bool := true;
      end;
    if ( cnt = 8 ) and ( bool ) then
      inc( ans );
  end;

  writeln( ans );
end.