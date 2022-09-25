program problem3;
type coord = record
               x, y: byte;
             end;

var s: array[ 1..8, 1..8 ] of boolean;
    turns: array[ 0..1, 1..64 ] of coord;
    chr: char;
    last_cnt, curr_cnt, turn, currIndex, lastIndex, maxCoord, i, j, k, l: longWord;
    b: boolean;

begin
  for i := 1 to 8 do
    for j := 1 to 8 do
      s[i][j] := false;

  for i := 8 downTo 1 do
  begin
    for j := 1 to 8 do
    begin
      read( chr );
      if ( chr = 'S' ) then
        s[j][i] := true;
    end;
    readln;
  end;

  turn := 0;
  curr_cnt := 1;
  turns[0][1].x := 1;
  turns[0][1].y := 1;

  while true do
  begin
    inc( turn );
    currIndex := turn mod 2;
    lastIndex := ( turn + 1 ) mod 2;
    maxCoord := turn + 1;
    last_cnt := curr_cnt;
    curr_cnt := 0;

    for i := 1 to maxCoord do
      for j := 1 to maxCoord do
        for k := 1 to last_cnt do
          if ( abs( turns[ lastIndex ][k].x - i ) <= 1 ) and ( abs( turns[ lastIndex ][k].y - j ) <= 1 ) and ( not s[i][j] ) and ( not s[i][j+1] ) then
          begin
            inc( curr_cnt );
            turns[ currIndex ][ curr_cnt ].x := i;
            turns[ currIndex ][ curr_cnt ].y := j;
            b := true;
            for l := (j+1) to 8 do
              if ( s[i][l] ) then
                b := false;

            if b then
            begin
              writeln( 'WIN' );
              halt;
            end;

            break;
          end;

    if ( curr_cnt = 0 ) then
    begin
      writeln( 'LOSE' );
      halt;
    end;

    for i := 1 to 8 do
      for j := 1 to 7 do
      begin
        if ( i = 1 ) and ( s[i][j] ) then
          s[i][j] := false;
        if ( s[i][j+1] ) then
        begin
          s[i][j] := true;
          s[i][j+1] := false;
        end;
      end;
  end;
end.