uses math;
var
  a,b,c,ans1,ans2:longint;
  i:longint;
begin
  read(a,b,c);
  ans2:=a*c;

  while a<>1 do
    begin
      i:=1;
      while i<=a do
        i:=i*2;
      i:=i div 2;
      inc(ans1,2*i*b+i);
      dec(a,i div 2);
    end;

  writeln(ans1 div 2,' ',ans2);
end.