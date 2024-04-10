var s:string;
 k,i:longint;
begin
read (s);
read (k);
for i:=1 to length (s) do
        begin
         if ord ('Z')< ord (s[i]) then
                begin
                if (ord ('a')+k-1 >= ord(s[i])) and (ord ('a') <= ord(s[i]))
                        then s[i]:=chr (ord (s[i])-(ord('a')-ord ('A')));
                end
                else
                begin
                if (ord ('A')+k-1< ord (s[i])) then
                        s[i]:= chr (ord (s[i])+(ord('a')-ord ('A')))
                end;
        end;
writeln (s);
end.