var s:string;
    n,i,x:longint;
begin
readln (n);
x:=0;
for i:=1 to n do 
    begin
     readln (s);
     if (s[1]='+') and (s[2]='+') then x:=x+1;
     if (s[1]='-') and (s[2]='-') then x:=x-1;
     if (s[3]='+') and (s[2]='+') then x:=x+1;
     if (s[3]='-') and (s[2]='-') then x:=x-1;
    end;
write(x);
end.