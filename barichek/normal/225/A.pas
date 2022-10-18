uses math;
var
  a,b,n,x:longint;
  i:longint;
begin
  read(n,x);
  read(a,b);
  for i:=1 to n-1 do
    begin
      read(a,b);
      if (a=x) or (b=x) or (a=7-x) or (b=7-x) then begin writeln('NO'); halt; end;
    end;
  writeln('YES');
end.