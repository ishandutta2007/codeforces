program problem2;
type tArr = array[1..100, 0..100] of string[21];

function calc( t: word; s: tArr; i, c: word ): word;
var j, cnt: word;
    str: string[20];

begin
  cnt := 0;

  for j := 1 to c do
  begin
    str := s[i][j];

    if ( str[1] = str[2] ) and ( str[1] = str[4] ) and ( str[1] = str[5] ) and ( str[1] = str[7] ) and ( str[1] = str[8] ) then
    begin
      if ( t = 0 ) then
        inc( cnt );
    end
    else if ( str[1] > str[2] ) and ( str[2] > str[4] ) and ( str[4] > str[5] ) and ( str[5] > str[7] ) and ( str[7] > str[8] ) then
    begin
      if ( t = 1 ) then
        inc( cnt );
    end
    else if ( t = 2 ) then
      inc( cnt );
  end;

  calc := cnt;
end;

var n, i, j, cnt, c: word;
    s: tArr;
    max: array[0..2, -1..100] of integer;
    str: array[0..2] of string;

begin
  str[0] := 'call a taxi';
  str[1] := 'order a pizza';
  str[2] := 'go to a cafe with a wonderful girl';
  max[0][0] := -1;
  max[1][0] := -1;
  max[2][0] := -1;

  readln( n );
  for i := 1 to n do
  begin
    read( cnt );
    readln( s[i][0] );
    for j := 1 to cnt do
    begin
      readln( s[i][j] );
    end;

    for j := 0 to 2 do
    begin
      c := calc( j, s, i, cnt );
      if ( c > max[j][0] ) then
      begin
        max[j][0] := c;
        max[j][-1] := 1;
        max[j][1] := i;
      end
      else if ( c = max[j][0] ) then
      begin
        inc( max[j][-1] );
        max[j][ max[j][-1] ] := i;
      end;
    end;

  end;

  for j := 0 to 2 do
  begin

    write( 'If you want to ' + str[j] + ', you should call:' );
    for i := 1 to max[j][-1] do
    begin
      if ( i > 1 ) then
        write( ',' );
      write( s[ max[j][i] ][0] );
    end;
    writeln( '.' );

  end;
end.