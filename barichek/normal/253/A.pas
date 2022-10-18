uses math;
var
  n,m:longint;
  i,j:longint;
begin
  assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset (input);
  rewrite (output);

  readln(n,m);
  if n>=m then
    begin
      for i:=1 to m do
        write('BG');
      for i:=1 to n-m do
        write('B');
    end;
  if n<m then
    begin
      for i:=1 to n do
        write('GB');
      for i:=1 to m-n do
        write('G');
    end;
end.