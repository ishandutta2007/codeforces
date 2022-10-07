var
  al, ar, bl, br: longint;

function asd(x, y: longint): boolean;
begin
  if (x - 1 <= y) and ((y - 1) div 2 <= x) then
    asd := true
  else
    asd := false;

end;

begin
  read(al, ar);
  read(bl, br);
  if (asd(al, br)) or (asd(ar, bl)) then write('YES') else write('NO');


end.