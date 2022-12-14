var s1,s2:string;
h1,h2:array[1..100]of char;
i,k,o,j,err:integer;
begin
readln(s1);
readln(s2);
if s1=s2 then write(0) else
        begin
        for i:=1 to length(s1) do
                if err<>1 then
                begin
                if s1[i]=s2[i] then
                        for j:=1 to k do
                                if (h1[j]=s1[i]) or (h2[j]=s1[i]) then err:=1;
                if s1[i]<>s2[i] then
                        begin
                        o:=0;
                        for j:=1 to k do
                                begin
                                if ((h1[j]=s1[i]) and (h2[j]=s2[i])) or ((h1[j]=s2[i]) and (h2[j]=s1[i])) then inc(o)
                                else if (h1[j]=s1[i]) or (h1[j]=s2[i]) or (h2[j]=s1[i]) or (h2[j]=s2[i]) then err:=1;
                                end;
                        if o=0 then
                                begin
                                for j:=1 to i-1 do
                                        if (s2[j]=s1[i]) or (s2[j]=s2[i]) then err:=1;
                                inc(k);
                                h1[k]:=s1[i];
                                h2[k]:=s2[i];
                                end;
                        s2[i]:=s1[i];
                        end;
                end;
        if err=1 then write(-1) else
        if s1=s2 then
                begin
                writeln(k);
                for i:=1 to k do
                        writeln(h1[i],' ',h2[i]);
                end else write(-1);
        end;
end.