uses math;

var
  a:array[1..10000]of longint;
  n,k:longint;
  i,j,t:longint;
begin
  read(n,k);
  for i:=1 to n do
    read(a[i]);

  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]<a[j] then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
        end;

  if k>n then begin writeln(-1); halt; end;
  if k=n then begin writeln(0,' ',0); halt; end;
  writeln(a[k],' ',a[k]);
end.