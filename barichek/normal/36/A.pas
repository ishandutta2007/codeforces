uses math;
var
  a:array[1..10000]of char;
  b:array[1..10000]of longint;
  n,k,k2:longint;
  i,j:longint;
begin
  assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset (input);
  rewrite (output);

  readln(n);
  for i:=1 to n do
    read(a[i]);

  for k:=1 to n do
    if a[k]='1' then break;
  for k2:=k+1 to n do
    if a[k2]='1' then break;

  for i:=k2+1 to n do
    if a[i]='1' then
      begin
        if i-k2<>k2-k then begin writeln('NO'); halt; end
        else begin k:=k2; k2:=i; end;
      end;

  writeln('YES');
end.