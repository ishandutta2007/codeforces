var max,min,c,s,n,i:longint;
begin
 readln(n);
 read(min);max:=min;s:=0;
 for i:=2 to n do
 begin
  read(c);
  if c>max then begin max:=c;inc(s);end;
  if c<min then begin min:=c;inc(s);end;
 end;
 writeln(s);
end.