uses math;
var
  a:array[1..100]of boolean;
  n,m,z:longint;
  i,j:longint;
begin
  read(n,m);

  for i:=1 to n do
    begin
      read(j);
      for j:=1 to j do
        begin
          read(z);
          a[z]:=true;
        end;
    end;

  for i:=1 to m do
    if not a[i] then begin writeln('NO'); halt; end;

  writeln('YES')
end.