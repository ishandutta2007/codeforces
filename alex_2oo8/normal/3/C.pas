program problem3;
type tArr = array[ 0..8, 1..3, 0..1 ] of longWord;

var arr: array[ 1..3, 1..3 ] of longWord;

function compare( arr: tArr ): boolean;
var i, j: longWord;
    bool: boolean;
begin
  bool := false;
  for i := 1 to 3 do
    for j := 1 to 3 do
      if ( arr[1][i][0] = arr[2][j][0] ) and ( arr[1][i][1] = arr[2][j][1] ) then
      begin
        bool := true;
        break;
        break;
      end;

  compare := bool;
end;

procedure getWins( var win: tArr );
var i, j: longWord;
    bool: boolean;
begin
  win[0][1][0] := 0;

  for i := 1 to 3 do
  begin
    bool := true;
    for j := 2 to 3 do
      if ( arr[i][j] <> arr[i][1] ) then
        bool := false;

    if bool and ( arr[i][1] <> 0 ) then
    begin
      inc( win[0][1][0] );
      win[ win[0][1][0] ][1][0] := i;
      win[ win[0][1][0] ][1][1] := 1;
      win[ win[0][1][0] ][2][0] := i;
      win[ win[0][1][0] ][2][1] := 2;
      win[ win[0][1][0] ][3][0] := i;
      win[ win[0][1][0] ][3][1] := 3;
    end;

    bool := true;
    for j := 2 to 3 do
      if ( arr[j][i] <> arr[1][i] ) then
        bool := false;

    if bool and ( arr[1][i] <> 0 ) then
    begin
      inc( win[0][1][0] );
      win[ win[0][1][0] ][1][0] := 1;
      win[ win[0][1][0] ][1][1] := i;
      win[ win[0][1][0] ][2][0] := 2;
      win[ win[0][1][0] ][2][1] := i;
      win[ win[0][1][0] ][3][0] := 3;
      win[ win[0][1][0] ][3][1] := i;
    end;
  end;

  if ( arr[1][1] = arr[2][2] ) and ( arr[2][2] = arr[3][3] ) and ( arr[1][1] <> 0 ) then
  begin
    inc( win[0][1][0] );
    win[ win[0][1][0] ][1][0] := 1;
    win[ win[0][1][0] ][1][1] := 1;
    win[ win[0][1][0] ][2][0] := 2;
    win[ win[0][1][0] ][2][1] := 2;
    win[ win[0][1][0] ][3][0] := 3;
    win[ win[0][1][0] ][3][1] := 3;
  end;

  if ( arr[1][3] = arr[2][2] ) and ( arr[2][2] = arr[3][1] ) and ( arr[1][3] <> 0 ) then
  begin
    inc( win[0][1][0] );
    win[ win[0][1][0] ][1][0] := 1;
    win[ win[0][1][0] ][1][1] := 3;
    win[ win[0][1][0] ][2][0] := 2;
    win[ win[0][1][0] ][2][1] := 2;
    win[ win[0][1][0] ][3][0] := 3;
    win[ win[0][1][0] ][3][1] := 1;
  end;

end;

var n1, n2, i, j: longWord;
    chr: char;
    win: tArr;
    str: array[1..2] of string;

begin
  str[1] := 'first';
  str[2] := 'second';

  n1 := 0;
  n2 := 0;

  for i := 1 to 3 do
  begin
    for j := 1 to 3 do
    begin
      read( chr );
      if ( chr = '.' ) then
        arr[i][j] := 0
      else if ( chr = 'X' ) then
      begin
        arr[i][j] := 1;
        inc( n1 );
      end
      else if ( chr = '0' ) then
      begin
        arr[i][j] := 2;
        inc( n2 );
      end;
    end;
    readln;
  end;

  if not ( ( n1 - n2 ) in [0..1] ) then
  begin
    writeln( 'illegal' );
    halt;
  end;

  getWins( win );

  if ( win[0][1][0] > 2 ) or ( ( win[0][1][0] = 2 ) and ( not compare( win ) ) ) then
  begin
    writeln( 'illegal' );
    halt;
  end;

  if ( win[0][1][0] > 0 ) then
  begin
    if ( ( arr[ win[1][1][0] ][ win[1][1][1] ] = 2 ) and ( n2 < n1 ) ) or ( ( arr[ win[1][1][0] ][ win[1][1][1] ] = 1 ) and ( n1 = n2 ) ) then
    begin
      writeln( 'illegal' );
      halt;
    end;

    writeln( 'the ', str[ arr[ win[1][1][0] ][ win[1][1][1] ] ], ' player won' );
    halt;
  end;

  if ( n1 + n2 ) = 9 then
    writeln( 'draw' )
  else if ( n1 > n2 ) then
    writeln( str[2] )
  else
    writeln( str[1] );
end.