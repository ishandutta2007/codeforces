uses math;
var
  n,a,mini,maxi,ans:longint;
  i:longint;
begin
  read(n,mini);
  maxi:=mini;
  ans:=0;

  for i:=1 to n-1 do
    begin
      read(a);
      if (a<mini) or (a>maxi) then inc(ans);
      mini:=min(mini,a);
      maxi:=max(maxi,a);
    end;

  writeln(ans);
end.