var a,b,c,i:longint;s,t:string;
begin
 readln(a,b);
 str(b,s);
 for i:=1 to length(s) do
  t:=s[i]+t;
 val(t,b);
 writeln(a+b);
end.