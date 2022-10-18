uses math;
var
  a:array[1..1000,1..1000] of longint;
  n,m,ans:longint;
  i,j,o:longint;
begin
  read(n,m);
  for i:=1 to n do
    for j:=1 to 2*m do
      read(a[i,j]);

  ans:=n*m;
  for i:=1 to n do
    begin
      o:=1;
      for j:=1 to m do
        begin
          if a[i,o]+a[i,o+1]=0 then dec(ans);
          inc(o,2);
        end;
    end;
  writeln(ans);
end.