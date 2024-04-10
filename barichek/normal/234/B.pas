uses math;
var
  a,b:array[1..10000]of longint;
  n,k,z:longint;
  i,j,t:longint;
begin
  assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset (input);
  rewrite (output);

  read(n,k);
  for i:=1 to n do
    read(a[i]);
  b:=a;

  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]<a[j] then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
        end;
  writeln(a[k]);
  z:=0;
  for i:=1 to n do
    begin
      if b[i]>=a[k] then begin write(i,' '); inc(z); end;
      if z=k then break;
    end;
end.