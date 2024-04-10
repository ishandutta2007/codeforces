uses math;
var
  n,zn,mini,sum:int64;
  i:longint;
begin
  read(n);

  mini:=sqr(maxlongint);
  for i:=1 to n do
    begin
      read(zn);
      if zn mod 2=1 then mini:=min(mini,zn);
      inc(sum,zn);
    end;

  if sum mod 2=1 then sum:=sum-mini;
  writeln(sum)
end.