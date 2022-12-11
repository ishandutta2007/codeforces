var s:string;
    t,i:longint;
begin
 readln(t);
 s:='abcd';
 while t>=4 do
 begin
  write(s);
  dec(t,4);
 end;
 for i:=1 to t do
  write(s[i]);
end.