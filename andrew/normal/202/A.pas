var
 c,c1:char;
 i:longint;
begin
 c1:=#1;
 while not eoln do
 begin 
  read(c);
  if c=c1 then inc(i);
  if c>c1 then
  begin
   c1:=c;
   i:=1;
  end;
 end;
 for i:=i downto 1 do write(c1);
 writeln;
end.