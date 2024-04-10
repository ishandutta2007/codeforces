uses math;
var
  n:longint;
begin
  read(n);
  case n of
    0,1,2,3,4,5,6,7,8,9,10,22,23,24,25:write(0);
    11,12,13,14,15,16,17,18,19,21:write(4);
    20:write(15);
  end;
end.