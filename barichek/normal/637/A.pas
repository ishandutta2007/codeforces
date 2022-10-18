uses math;
var
  a,ans,time:array[1..1000000]of longint;
  n,maxi,fula,fulatime:longint;
  i:longint;
begin
  read(n);
  for i:=1 to n do
    begin
      read(a[i]);
      inc(ans[a[i]]);
      time[a[i]]:=i;
    end;

  maxi:=-maxlongint;
  for i:=1 to n do
    maxi:=max(maxi,ans[a[i]]);

  fulatime:=maxlongint;
  for i:=1 to n do
    if (ans[a[i]]=maxi) and (time[a[i]]<fulatime) then
      begin
        fulatime:=time[a[i]];
        fula:=a[i];
      end;

  writeln(fula);
end.