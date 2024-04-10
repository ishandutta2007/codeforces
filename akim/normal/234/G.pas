var a,b,c,d,i:longint;
begin
 assign(input,'input.txt');reset(input);
 assign(output,'output.txt');rewrite(output);
 readln(a);b:=1;c:=0;
 while b<a do begin b:=b shl 1;inc(c);end;b:=b div 2;
 writeln(c);
 while b>=1 do
 begin
  c:=0;
  d:=0;
  while c<a do
  begin
   for i:=1 to b do
    if c+i<=a then inc(d);
   c:=c+b*2;
  end;
  write(d,' ');
  c:=0;
  while c<a do
  begin
   for i:=1 to b do
    if c+i<=a then write(c+i,' ');
   c:=c+b*2;
  end;
  writeln;
  b:=b div 2;
 end;
 close(input);close(output);
end.