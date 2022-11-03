var check,ans,i,j:longint;
st1,st:ansistring;
begin
readln(st);
readln(st1);
for i:=1 to length(st)-length(st1)+1 do
begin
        //writeln(i);
        check:=1;
        for j:=1 to length(st1) do
                begin
                //writeln(st[i],' ',st1[j]);
                if (st[i+j-1]<>st1[j]) then check:=0;
                end;
        if (check=1) then
                st[i+length(st1)-1]:='#';
        ans:=ans+check;
end;
writeln(ans);
end.