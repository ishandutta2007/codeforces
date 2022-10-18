uses math;
var
  x,y:array[1..10000]of longint;
  n,s,maxi:longint;
  i:longint;
begin
  read(n,s);
  maxi:=-1;
  for i:=1 to n do
    read(x[i],y[i]);

  for i:=1 to n do
    begin
      if x[i]<s then
        if y[i]=0 then maxi:=max(maxi,0)
        else maxi:=max(maxi,100-y[i]);
      if (x[i]=s) and (y[i]=0) then maxi:=max(maxi,0);
    end;
  writeln(maxi);
end.