
program A;
var
  i, z, x, y, sx, sy, sz, n: longint;

begin
 read(n);
  for i := 1 to n do
  begin
    read(x, y, z);
    sx := sx + x;
    sy := sy + y;
    sz := sz + z;
  end;
  if (sx = 0) and (sy = 0) and (sz = 0) then
    write('YES')
  else
    write('NO')

end.