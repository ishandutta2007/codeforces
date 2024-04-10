program problem2;

var a: byte;
    x, y, row, col, ans: longInt;

begin
  readln( a, x, y );
  if ( abs( x ) < a ) and ( ( y mod a ) <> 0 ) then
  begin
    row := ( y + a - 1 ) div a;
    if ( ( row mod 2 ) = 0 ) or ( row = 1 ) then
    begin
      if ( abs( x ) < ( (a+1) div 2 ) ) then
        ans := row + ( ( row - 2 ) div 2 )
      else
        ans := -1;
    end
    else
    begin
      if ( x <> 0 ) then
      begin
        if ( x < 0 ) or ( y < a ) then
          col := 0
        else
          col := 1;
        ans := row + ( ( row - 2 ) div 2 ) + col;
      end
      else
        ans := -1;
    end;
  end
  else
    ans := -1;

  writeln( ans );
end.