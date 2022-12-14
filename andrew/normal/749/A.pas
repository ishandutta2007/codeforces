var
 s,s1,i,j,i1,j1,ch1,ch2,k,l:longint;
begin
 readln(s);
 if s mod 2=0 then
 begin
  writeln(s div 2);
  for i:=1 to s div 2 do write(2,' ');
  halt;
 end;
{ if s mod 3=0 then
 begin
  writeln(s div 3);
  for i:=1 to s div 3 do write(3,' ');
  halt;
 end; }
 writeln(s div 2 );
 for i:=1 to s div 2-1 do write(2,' ');
 writeln(3);
end.