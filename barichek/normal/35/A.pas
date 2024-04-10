uses math;
var
  l,r,ans:longint;
  i:longint;
begin
  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);

  read(ans);

  for i:=1 to 3 do
    begin
      read(l,r);
      if l=ans then ans:=r
      else if r=ans then ans:=l;
    end;

  writeln(ans);
end.