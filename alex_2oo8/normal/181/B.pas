program problem2;
type rec = record
             x, y: longInt;
           end;
     tArr = array[1..3000] of rec;

var n, i, j, ans: longInt;
    p: tArr;
    arr: array[ -1000..1000, -1000..1000 ] of boolean;

begin
  ans := 0;

  for i := -1000 to 1000 do
    for j := -1000 to 1000 do
      arr[i][j] := false;

  readln( n );
  for i := 1 to n do
  begin
    readln( p[i].x, p[i].y );
    arr[ p[i].x ][ p[i].y ] := true;
  end;

  for i := 1 to (n-1) do
    for j := (i+1) to n do
      if ( ( ( p[i].x + p[j].x ) mod 2 ) = 0 ) and ( ( ( p[i].y + p[j].y ) mod 2 ) = 0 ) and ( arr[ ( p[i].x + p[j].x ) div 2 ][ ( p[i].y + p[j].y ) div 2 ] ) then
        inc( ans );

  writeln( ans );
end.