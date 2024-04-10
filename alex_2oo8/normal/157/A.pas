program problem1;
type tArr = array[1..30, 1..30] of byte;

function win( a: tArr; x, y, n: byte ): boolean;
var v, h: word;
    i, j: byte;
begin
  v := 0;
  h := 0;
  for i := 1 to n do
    h := h + a[x][i];
  for j := 1 to n do
    v := v + a[j][y];

  if ( v > h ) then
    win := true
  else
    win := false;
end;

var n, i, j: byte;
    cnt: word;
    a: tArr;

begin
  cnt := 0;

  readln(n);
  for i := 1 to n do
  begin
    for j := 1 to n do
    begin
      read( a[i][j] );
    end;
    readln;
  end;

  for i := 1 to n do
    for j := 1 to n do
    begin
      if win( a, i, j, n ) then
        inc( cnt );
    end;

  writeln( cnt );
end.