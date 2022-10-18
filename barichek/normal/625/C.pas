uses math;
var
  a:array[1..1000,1..1000]of longint;
  n,k,nom,sum:longint;
  i,j:longint;
begin
  readln(n,k);

  nom:=1;
  for i:=1 to n do
    for j:=1 to k-1 do
      begin
        a[i,j]:=nom;
        inc(nom);
      end;
  for i:=1 to n do
    for j:=k to n do
      begin
        a[i,j]:=nom;
        inc(nom);
      end;

  for i:=1 to n do
    inc(sum,a[i,k]);
  writeln(sum);

  for i:=1 to n do
    begin
      for j:=1 to n do
        write(a[i,j],' ');
      writeln;
    end;
end.